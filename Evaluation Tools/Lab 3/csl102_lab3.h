/**
 * In the function you are given and array.
 * Assume the size of array to be odd number.
 * Find median of the given array, i.e. the middle element.
 * Find out the k'th' smallest element in the array, where k < size of array.
 * Return absolute value of their difference i.e. abs(median - k'th' smallest).
 * 
 * For example, arr = [1,7,21,6,8,13,78,3,5]. 
 * Median = 8; k'th' smallest = 5, when k = 3. abs(8 - 3) = 5, so return 5.
 * */ 
unsigned long csl102_diff_k_median(
    short array[], 
    unsigned short szArr,
    unsigned short k
);


/**
 * In this function, you are given two arrays.
 * 
 * You must rearrange/shuffle the values in arrayOne and arrayTwo.
 * 
 * Values from arrayOne can be put in arrayTwo and vice-versa.
 * 
 * Your implementation must rearrange/shuffle the values such that
 * value at any index of arrayOne must be less than the value at any index
 * of arrayTwo.
 * 
 * In addition, you must have the order of values in arrayOne in ascending order.
 * And, the order of values in arrayTwo must be descending order.
 * 
 * Assume no duplicate values in arrayOne and arrayTwo individually and together.
 * 
 * szArrOne = number of elements in arrayOne
 * szArrTwo = number of elements in arrayTwo
 * arrayOne and arrayTwo could have different sizes
 * 
 * For example
 * Input: arrayOne = [4, 67, -9, 3, 0, 54, -89]; arrayTwo = [5, 21, -21, -5, 64, -1, 30]
 * Modified arrayOne = [-89, -21, -9, -5, -1, 0, 3] (ascending order)
 * Modified arrayTwo = [67, 64, 54, 30, 21, 5, 4] (descending order)
 * 
 */

void csl102_sort_lab3(
short arrayOne[], 
unsigned short szArrOne,
short arrayTwo[],
unsigned short szArrTwo);