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

// tortoise approach
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *start = new ListNode();
        start->next = head;
        ListNode *slow = start;
        ListNode *fast = start;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return start->next;
    }
};