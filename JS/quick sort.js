// 快速排序 http://bubkoo.com/2014/01/12/sort-algorithm/quick-sort/

function quickSort(array){
	
	if( array.length <= 1){
		return array;
	}

	var pivotIndex = Math.floor(array.length/2);
	var pivot = array.splice(pivotIndex, 1)[0];
	var left = [];
	var right = [];
	for( var i = 0 ; i < array.length ; i ++ ){
		if( array[i] < pivot)
			left.push(array[i]);
		else
			right.push(array[i]);
	}

	return quickSort(left).concat([pivot], quickSort(right));
}

function quickSortInPlace(array) {
	// 交换元素位置
	function swap(array, i, k) {
		var temp = array[i];
		array[i] = array[k];
		array[k] = temp;
	}
	// 数组分区，左小右大
	function partition(array, left, right) {
		var storeIndex = left;        
		var pivot = array[right]; // 直接选最右边的元素为基准元素
		for (var i = left; i < right; i++) {
			if (array[i] < pivot) {
				if( i !== storeIndex)
					swap(array, storeIndex, i);
				storeIndex++; // 交换位置后，storeIndex 自增 1，代表下一个可能要交换的位置
			}
		}
		swap(array, right, storeIndex); // 将基准元素放置到最后的正确位置上
		return storeIndex;
	}
	function sort(array, left, right) {
		if (left > right) {
			return;
		}
		var storeIndex = partition(array, left, right);
		sort(array, left, storeIndex - 1);
		sort(array, storeIndex + 1, right);
	}
	sort(array, 0, array.length - 1);
	return array;
}
var arr = [3,7,8,5,2,1,9,5,12];
console.log(quickSortInPlace(arr));