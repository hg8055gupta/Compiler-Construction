void printPostOrder(parseNode *curr, parseNode *par)
{

    if (curr == NULL)
        return;

    if (!strcmp(curr->val, ""))
        return;

    if (curr->child != NULL)
        printInOrder(curr->child, curr);


    if (curr->sibling != NULL)
    {
        printInOrder(curr->sibling, NULL);
        printf("|-%s-|\n", curr->val);
    }

    if (curr->sibling == NULL && curr->child == NULL)
    {
        if (strcmp(curr->val, ""))
            printf("|-%s-|\n", curr->val);
    }
    
}
