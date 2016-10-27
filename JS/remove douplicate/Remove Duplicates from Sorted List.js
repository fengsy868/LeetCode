//Remove Duplicates from Sorted List

/*
	Given a sorted linked list, delete all duplicates such that each element appear only once.

	For example,
	Given 1->1->2, return 1->2.
	Given 1->1->2->3->3, return 1->2->3.
*/


/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    if(head === null || head.next === null)
    	return head;

    var currentNode = head;

    while(currentNode.next !== null){
        next = currentNode.next;
    	if(currentNode.val === nextNode.val){
    		currentNode.next = nextNode.next;
    	} else {
    		currentNode = nextNode;
    		nextNode = currentNode.next;
    	}
    }

    return head;
};

function ListNode(val) {
    this.val = val;
    this.next = null;
 }

 var head  = new ListNode(1);
 var second = new ListNode(1);
 var third = new ListNode(1);

 head.next = second;
 second.next = third;

 console.log(deleteDuplicates(head));
