void addTwoNumber( ListNode* l1, ListNode* l2)
{
    if ( l1->next == NULL || l2->next == NULL){
        l1->val = (l1->val + l2->val) % 10;
    } else {
        addTwoNumber(l1->next, l2->next);
        l1->val = (l1->val + l2->val) % 10;
    }
}

// Esboço da função recursiva.
/* Posso fazer uma função em bool para retornar o Backtracking da soma anterior */