class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        // edge case conditions
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head; // keeping this prev node to get the previous node of slow pointer when we reach middle
        while (fast != NULL && fast->next != NULL)
        {
            if (slow != head)
                prev = prev->next; // since we want prev to start one step later than slow node
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
        return head;
    }
};

// 2nd way
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == nullptr)
            return nullptr;
        auto slow = head, fast = head->next->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};