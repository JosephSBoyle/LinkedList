### Development Notes

- Functions that take no arguments should have `void` in the parentheses in their header. E.g `foo()` should be `foo(void)`.
    This tells the compilers and linters that `foo` explicitly takes _no_ arguments rather than a variable number.

- `pragma once` in a `.h` file means the source will only be added once. This is useful in cases where the module is used in more than one place.
    For example, if you have two files, `foo.c` and `bar.c` and both want to include `baz.h`, then you would be defining two copies of everything in `baz.h`
    but because of `pragma once` the compiler avoids this.

- Name collisions: `C` doesn't support namespaces so it's important to consider naming collisions when using common expressions in names. A good alternative is to prefix
    the function names with a common string, e.g `add` -> `linked_list_add` | `ll_add`, `create` -> `linked_list_create` | `ll_create`.

- `malloc` can fail, in which case it returns `NULL`. Check that the value isn't `NULL` before casting to a pointer of another type:
    ```C
    void* ptr = malloc(sizeof(T));
    if (ptr==NULL){
        // raise error or return failure flag.
    } else {
        T* ptr = (T*)ptr; // safely cast to a pointer to an instance of type `T`.
    }
    ```