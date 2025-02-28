#!/bin/bash

# Check if the size argument is provided
if [ -z "$1" ]; then
	echo "Usage: $0 <size>"
	exit 1
fi

# Get the size from the first argument
size=$1

# Initialize an array to store the operations count
ops_results=()

# Define the thresholds
declare -A thresholds
thresholds[2]=1
thresholds[3]=2
thresholds[5]=12
thresholds[100]=1300
thresholds[500]=7000

# Function to get the next available threshold
get_threshold() {
	local size=$1
	for key in $(echo "${!thresholds[@]}" | tr ' ' '\n' | sort -n); do
		if [ "$size" -le "$key" ]; then
			echo "${thresholds[$key]}"
			return
		fi
	done
	echo ""
}

# Function to generate a random number within the range of MIN_INT to MAX_INT
generate_random_number() {
	local min=-2147483648
	local max=2147483647
	local range=$((max - min + 1))
	local random_number=$(od -An -N4 -tu4 </dev/urandom | tr -d ' ')
	echo $((random_number % range + min))
}

# Run the test 100 times
for i in {1..100}; do
	# Generate a list of random integers of the specified size
	numbers=$(for _ in $(seq 1 $size); do generate_random_number; done | tr '\n' ' ')

	# Call push_swap with the generated numbers and count the operations
	ops=$(./push_swap $numbers | wc -l)

	# Check the validity of the output using checker
	valid=$(./push_swap $numbers | ./checker_linux $numbers)

	# Store the operations count in the array
	ops_results+=($ops)

	# Get the threshold for the current size
	threshold=$(get_threshold $size)

	# Print the list and ops count if the threshold is exceeded or the output is invalid
	if [ -n "$threshold" ] && { [ $ops -gt $threshold ] || [ "$valid" = "KO" ]; }; then
		echo "LST: $numbers"
		echo "OPS: $ops"
		echo "CHK: $valid"
	fi
done

# Sort the operations results
sorted_ops=($(printf '%s\n' "${ops_results[@]}" | sort -n))

# Calculate the best, worst, median, and average operations result
best_ops=${sorted_ops[0]}
worst_ops=${sorted_ops[-1]}
median_ops=${sorted_ops[50]}
total_ops=$(
	IFS=+
	echo "$((${ops_results[*]}))"
)
average_ops=$((total_ops / 100))

# Print the results
echo "======================="
echo "List size  : $size"
echo "Max OPS    : $threshold"
echo "Best OPS   : $best_ops"
echo "Worst OPS  : $worst_ops"
echo "Median OPS : $median_ops"
echo "Average OPS: $average_ops"
echo "======================="

# Print the histogram
echo "Histogram of Operations Count:"
histogram_bins=10
bin_size=$(((worst_ops - best_ops) / histogram_bins))
bin_size=$((bin_size > 0 ? bin_size : 1))

# Array to store counts for each bin
declare -a bin_counts=()

# Calculate counts for each bin
for ((i = 0; i < histogram_bins; i++)); do
	bin_start=$((best_ops + i * bin_size))
	bin_end=$((bin_start + bin_size))
	count=0
	for ops in "${sorted_ops[@]}"; do
		if ((ops >= bin_start && ops < bin_end)); then
			((count++))
		fi
	done
	bin_counts[i]=$count
done

# Find the last non-empty bin
last_non_empty_bin=-1
for ((i = 0; i < histogram_bins; i++)); do
	if ((bin_counts[i] > 0)); then
		last_non_empty_bin=$i
	fi
done

# Calculate the maximum width of the bin labels
max_label_width=0
for ((i = 0; i <= last_non_empty_bin; i++)); do
	bin_start=$((best_ops + i * bin_size))
	bin_end=$((bin_start + bin_size))
	label="$bin_start - $bin_end"
	if ((${#label} > max_label_width)); then
		max_label_width=${#label}
	fi
done

# Print the histogram up to the last non-empty bin
for ((i = 0; i <= last_non_empty_bin; i++)); do
	bin_start=$((best_ops + i * bin_size))
	bin_end=$((bin_start + bin_size))
	count=${bin_counts[i]}
	label="$bin_start - $bin_end"
	printf "%-${max_label_width}s : " "$label"
	for ((j = 0; j < count; j++)); do
		echo -n "#"
	done
	echo " ($count)"
done
