//gfg
//only the logic part


Node *sorted(Node *head1, Node *head2){
   Node *result = NULL;
   if (head1 == NULL) {
      return head2;
   }
   if (head2 == NULL) {
      return head1;
   }
   if (head1->data < head2->data) {
      result = head1;
      result->next = sorted(head1->next, head2);
   } else {
      result = head2;
      result->next = sorted(head1, head2->next);
   }
   return result;
}


