#include <assert.h>
#include "linked_list.h"


/* Tests */
void main(){
    Node* sentinel = ll_new();
   
    ll_add(sentinel, 'h');
    ll_add(sentinel, 'e');
    ll_add(sentinel, 'l');
    ll_add(sentinel, 'l');
    ll_add(sentinel, 'o');

    ll_print(sentinel); // should print: ['h', 'e', 'l', 'l', '0']

    ll_replace(sentinel, 4, '0');
    ll_stringprint(sentinel); // should print: hell0

    // check that deleting works for a valid index
    assert(ll_del(sentinel, 4));
    // and fails when that index becomes invalid.
    assert(!ll_del(sentinel, 4));

    // check peaking an invalid index returns the sentinel node
    assert(sentinel == ll_peek(sentinel, 4));

    ll_stringprint(sentinel);
    ll_free(sentinel);
}
