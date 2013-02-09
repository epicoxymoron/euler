/*
                            0
                          1   2
                        3   4   5
                      6   7   8   9
                    10  11  12  13  14
                  15  16  17  18  19  20

0th row is 0
1st row is 1
2nd row is 3
3rd row is 6
4th row is 10
5th row is 15

nth row is sum(0:n)
0th row is sum(0:0) == 0
1th row is sum(0:1) == 1
2th row is sum(0:2) == 3
3th row is sum(0:3) == 6
4th row is sum(0:4) == 10
5th row is sum(0:5) == 15

row_start(row) = sum(0:n) == (n * n+1) / 2

left_child(row, pos) = row_start(row+1) + pos
left_child(4) == left_child(2, 1) == row_start(row+1) + pos == row_start(3) + 1 = 7

right_child(row, pos) = row_start(row+1) + pos + 1
right_child(4) == right_child(2, 1) == row_start(row+1) + pos + 1 == row_start(3) + 1 + 1 = 8

left_parent(row, pos) = row_start(row-1) + pos - 1
left_parent(4) == left_parent(2, 1) == row_start(row-1) + pos - 1 == row_start(1) + 1 - 1 = 1

right_parent(row, pos) = row_start(row-1) + pos
right_parent(4) == right_parent(2, 1) == row_start(row-1) + pos == row_start(1) + 1 = 2

left_parent_valid(row, pos) = left_parent(row, pos) >= row_start(row-1) and < row_start(row)
right_parent_valid(row, pos) = right_parent(row, pos) >= row_start(row-1) and < row_start(row)

size(rows) = row_start(rows+1) - 1
row(index) = ???
pos(index) = index - row_start(row(index))

                            75
                          95  64
                        17  47  82
                      18  35  87  10
                    20  04  82  47  65
                  19  01  23  75  03  34
                88  02  77  73  07  63  67
              99  65  04  28  06  16  70  92
            41  41  26  56  83  40  80  70  33
          41  48  72  33  47  32  37  16  94  29
        53  71  44  65  25  43  91  52  97  51  14
      70  11  33  28  77  73  17  78  39  68  17  57
    91  71  52  38  17  14  91  43  58  50  27  29  48
  63  66  04  68  89  53  67  30  73  16  69  87  40  31
04  62  98  27  23  09  70  98  73  93  38  53  60  04  23
*/


/*
 * this is the structure we'll be mimicking with 3 arrays
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define LEFTCHAR 'L'
#define RIGHTCHAR 'R'
#define LEAFCHAR 'F'

struct triangle_node {
	int 					value;
	struct triangle_node*	parent;
	struct triangle_node*	left;
	struct triangle_node*	right;
	char					largest_subtree_dir;
	int						largest_subtree_value;
};


unsigned long sum_from_1_to(unsigned long n) {
	return (n * (n+1)) / 2;
}

unsigned long num_rows(size_t num_elements) {
	size_t rows = 0;
	size_t val = 0;
	size_t inc = 0;
	while (val < num_elements) {
		rows++;
		inc++;
		val += inc;
	}
	if (val != num_elements) {
		return -1;
	}
	else {
		return rows;
	}
}

bool is_valid_size(size_t elements) {
	int sq = floor(sqrt(elements * 2));
	return (sum_from_1_to(sq) == elements);
}

size_t row_start(size_t row_num) {
	return sum_from_1_to(row_num);
}

size_t left_child_pos(size_t rownum, size_t curpos) {
	return row_start(rownum + 1) + curpos;
}

size_t right_child_pos(size_t rownum, size_t curpos) {
	return left_child_pos(rownum, curpos) + 1;
}

void find_longest_path(long data[], size_t num_elements, char *choice_buf) {
	size_t i = 0;
	unsigned long nrows = num_rows(num_elements);
	long sub_tree_sizes[num_elements];
	size_t rcpos, lcpos;

	// start 2 rows back, -1 for being 0-indexed, -1 for going up a level
	long cur_row = nrows - 2;

	// note that the last row is full of leaves
	size_t rstart = row_start(nrows - 1);
	size_t rend = row_start(nrows);

	for (i = 0; i < row_start(nrows - 1); i++) {
		choice_buf[i] = 'U';
		sub_tree_sizes[i] = -1;
	}
	// NUL-terminate
	choice_buf[num_elements] = 0;

	// deal with the last row first
	for (i = rstart; i < num_elements; i++) {
		//printf("%ld\n", i);
		choice_buf[i] = LEAFCHAR;
		sub_tree_sizes[i] = data[i];
	}

	// loop through parent rows
	while (cur_row >= 0L) {
		rstart = row_start(cur_row);
		rend = row_start(cur_row + 1);

		for (i = rstart; i < rend; i++) {
			lcpos = left_child_pos(cur_row, i - rstart);
			rcpos = lcpos + 1;
			if (sub_tree_sizes[lcpos] >= sub_tree_sizes[rcpos]) {
				// go left
				choice_buf[i] = LEFTCHAR;
				sub_tree_sizes[i] = sub_tree_sizes[lcpos] + data[i];
			}
			else {
				// go right
				choice_buf[i] = RIGHTCHAR;
				sub_tree_sizes[i] = sub_tree_sizes[rcpos] + data[i];
			}
		}

		cur_row--;
	}

	for (i = 0; i < num_elements; i++) {
		printf("%ld, ", sub_tree_sizes[i]);
	}
	printf("\n");
	printf("%s\n", choice_buf);
}

/*
struct trinagle_node* build_triangle(int values[], size_t length) {
	struct triangle_node** root = (struct triangle_node**) malloc(sizeof(struct triange_node*) * length);
	for (;;) {
		;
	}

}
*/

int main(int argc, char** argv) {
	//int i;
	size_t num_elements;

	long arr[] = {75, 95, 64, 17, 47, 82, 18, 35, 87, 10, 20, 4, 82, 47, 65, 
		19, 1, 23, 75, 3, 34, 88, 2, 77, 73, 7, 63, 67, 99, 65, 4, 28, 6, 
		16, 70, 92, 41, 41, 26, 56, 83, 40, 80, 70, 33, 41, 48, 72, 33, 47, 
		32, 37, 16, 94, 29, 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 70, 
		11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 91, 71, 52, 38, 17, 14, 
		91, 43, 58, 50, 27, 29, 48, 63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 
		69, 87, 40, 31, 4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 
		4, 23};

	num_elements = sizeof(arr) / sizeof(long);
	char *directions = (char *) malloc((num_elements + 1) * sizeof(char));
	directions[num_elements] = 0;
	
	find_longest_path(arr, num_elements, directions);
	printf("%s\n", directions);

	test();
}

void test() {
	test_num_rows();
	test_l();
	test_r();
}

void test_num_rows() {
	size_t i;
	size_t next_valid = 1;
	for (i = 1; i < 10000; i++) {
		if (!is_valid_size(i)) {
			assert(num_rows(i) == -1);
		}
		else {
			assert(num_rows(i) == next_valid++);
		}
	}
}

void test_l() {
	size_t i;
	size_t num_elements;

	long arr[120];
	for (i = 0; i < 120; i++) {
		arr[i] = 120 - i;
	}

	num_elements = sizeof(arr) / sizeof(long);
	char *directions = (char *) malloc((num_elements + 1) * sizeof(char));
	directions[num_elements] = 0;
	
	find_longest_path(arr, num_elements, directions);

	for (i = 0; i < 120; i++) {
		assert(directions[i] == 'L' || directions[i] == 'F');
	}
}

void test_r() {
	size_t i;
	size_t num_elements;

	long arr[120];
	for (i = 0; i < 120; i++) {
		arr[i] = i;
	}

	num_elements = sizeof(arr) / sizeof(long);
	char *directions = (char *) malloc((num_elements + 1) * sizeof(char));
	directions[num_elements] = 0;
	
	find_longest_path(arr, num_elements, directions);
	for (i = 0; i < 120; i++) {
		assert(directions[i] == 'R' || directions[i] == 'F');
	}

}
