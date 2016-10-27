//Remove Duplicates from Sorted Array

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/
var removeDouplicates = function(nums){

	if(nums.length < 3)
		return nums.length;

	var i = 1 ; 
	var value ; 
	while ( i < nums.length){
		if(nums[i- 1] === nums[i]) {

			if(value == nums[i]){
				nums.splice(i, 1);
			} else {
				value = nums[i];
				i ++;
			}
		}
		else 
			i++;
	}

	return nums;
}

console.log(removeDouplicates([1,1,1,2,2,3]));