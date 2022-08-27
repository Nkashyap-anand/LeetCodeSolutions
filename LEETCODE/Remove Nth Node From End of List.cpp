class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        int count = 0;

        ListNode *last = head;

        while (last != NULL)
        {
            last = last->next;
            count++;
        }

        if (count == 1)
            return NULL;

        ListNode *temp = head;
        ListNode *prev = head;

        int step = 0;

        if (step == count - n)
        {
            head = head->next;
            return head;
        }

        while (step < count - n)
        {
            prev = temp;
            temp = temp->next;

            step++;
        }

        prev->next = temp->next;

        return head;
    }
};