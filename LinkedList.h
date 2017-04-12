class ListNode
{
    public:
    ListNode(int data)
    {
        
    }

    ListNode(const ListNode& node, int data) : m_data(data) // m_next(node),
    {

    }

    private: 
        int m_data;
        //ListNode m_next;
};