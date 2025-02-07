class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val  # Stores the value of the node
        self.next = next  # Pointer to the next node in the linked list

def swapNodes(head: ListNode, k: int) -> ListNode:
    # Initialize two pointers, first and last, to track the nodes to be swapped
    first = last = head
    
    # Move first pointer to the k-th node from the beginning
    for _ in range(k - 1):
        first = first.next
    
    # Use a temporary pointer temp to traverse to the end of the list
    temp = first
    while temp.next:
        temp = temp.next
        last = last.next
    
    # Swap the values of the first and last node
    first.val, last.val = last.val, first.val
    
    return head

# function to create a linked list from a list of values
def create_linked_list(lst):
    if not lst:
        return None  # Return none if an empty list
    head = ListNode(lst[0])  # Create the head node
    current = head  # Pointer to traverse and create nodes
    for val in lst[1:]:
        current.next = ListNode(val)  
        current = current.next  # Move to the newly created node
    return head

# function to convert a linked list back to a Python list for easy output
def linked_list_to_list(head):
    result = []
    while head:
        result.append(head.val)  
        head = head.next 
    return result

def main():
    head = create_linked_list([1, 2, 3, 4, 5])  
    k = 2 
    new_head = swapNodes(head, k)  
    print(linked_list_to_list(new_head))  
if __name__ == "__main__":
    main()
