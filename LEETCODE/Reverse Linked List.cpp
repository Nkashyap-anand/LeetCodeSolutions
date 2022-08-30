class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == NULL)
            return NULL;

        ListNode *newHEAD = NULL;

        while (head != NULL)
        {
            ListNode *NEXT = head->next;
            head->next = newHEAD;
            newHEAD = head;
            head = NEXT;
        }
        return newHEAD;
    }
};