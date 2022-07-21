class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *next = NULL, *prev = NULL, *current = head;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        ListNode *current = head, *prev = NULL;

        int count = 1;

        while (count != left)
        {
            prev = current;
            current = current->next;
            count++;
        }

        ListNode *start = current;

        while (count != right)
        {
            current = current->next;
            count++;
        }

        ListNode *rest = current->next;

        current->next = NULL;

        ListNode *newHead = reverse(start);

        if (prev != NULL)
        {
            prev->next = newHead;
        }

        current = newHead;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = rest;

        if (left == 1)
        {
            return newHead;
        }
        return head;
    }
};