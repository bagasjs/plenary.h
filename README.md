# Plenary.h
A collection of C/C++ functions, macros, types that I don't want to reimplement. The name is inspired by plenary.lua for neovim.

## Cheatsheets
### Temporary Allocator

### String View
```c
// types
struct String_View;

// functions
String_View sv_from_parts(const char* data, size_t n);
String_View sv_from_cstr(const char* cstr); 
String_View sv_slice(String_View strv, size_t start, size_t end);
int sv_find_cstr(String_View strv, const char* sth, size_t index);
int sv_find(String_View strv, String_View sth, size_t index);
bool sv_contains(String_View strv, String_View sth);
bool sv_has_prefix(String_View strv, String_View prefix);           
bool sv_has_suffix(String_View strv, String_View suffix);
bool sv_eq(String_View a, String_View b);
String_View sv_ltrim(String_View strv);
String_View sv_rtrim(String_View strv);
String_View sv_take_left_while(String_View strv, bool (*predicate)(char x));
String_View sv_chop_left(String_View* strv, size_t n);
String_View sv_chop_right(String_View* strv, size_t n);
String_View sv_chop_left_while(String_View* strv, bool (*predicate)(char x));
String_View sv_chop_by_delim(String_View* strv, char delim);
String_View sv_chop_by_sv(String_View* strv, String_View sv);
int sv_to_int(String_View strv);
```

### Dynamic Array
```c
#define da(T) // generate a dynamic array struct of type T could be used for type definition i.e 'typedef da(Token) Token_List;'
#define da_free(da) // free an instance of da(T)
#define da_append(da, item) // append an item to an instance of da(T)
#define da_append_many(da, new_items, new_items_count) // append many items to an instance of da(T)

// da_free(), da_apend(), da_append_many() take pointer
```

### Temporary Allocator
```c
void *temp_alloc(size_t size);
void temp_reset(void);                      // reset the usage of the allocator /!\ It doesnt change the base pointer
size_t temp_usage(void);                    // get the current usage of the allocator
char *temp_sprintf(const char *fmt, ...);   // securely generate a formatted string using the temporary allocator 
```

### Others
