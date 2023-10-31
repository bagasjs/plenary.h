#define PLENARY_IMPLEMENTATION
#include "plenary.h"
#include <stdio.h>

typedef struct {
    int id;
    const char* name;
} Entity;

void string_view_tests(void);
void da_tests(void);

int main(void)
{
    string_view_tests();
    da_tests();
}

void string_view_tests(void)
{
    String_View text = sv_from_cstr("Hello, World");

    String_View comparator = sv_from_cstr("Hell");
    printf("\""SV_FMT"\" has prefix \"" SV_FMT "\" => %s\n", 
            SV_ARGV(text),
            SV_ARGV(comparator),
            sv_has_prefix(text, comparator) ? "true" : "false"
          );

    comparator = sv_from_cstr("hell");
    printf("\""SV_FMT"\" has prefix \"" SV_FMT "\" => %s\n", 
            SV_ARGV(text),
            SV_ARGV(comparator),
            sv_has_prefix(text, comparator) ? "true" : "false"
          );

    comparator = sv_from_cstr("orld");
    printf("\""SV_FMT"\" has suffix \"" SV_FMT "\" => %s\n", 
            SV_ARGV(text),
            SV_ARGV(comparator),
            sv_has_suffix(text, comparator) ? "true" : "false"
          );

    comparator = sv_from_cstr("orlD");
    printf("\""SV_FMT"\" has suffix \"" SV_FMT "\" => %s\n", 
            SV_ARGV(text),
            SV_ARGV(comparator),
            sv_has_suffix(text, comparator) ? "true" : "false"
          );

    comparator = sv_from_cstr("Hello, World");
    printf("\""SV_FMT"\" is equal to \"" SV_FMT "\" => %s\n", 
            SV_ARGV(text),
            SV_ARGV(comparator),
            sv_eq(text, comparator) ? "true" : "false"
          );

    comparator = sv_from_cstr("hello, world");
    printf("\""SV_FMT"\" is equal to \"" SV_FMT "\" => %s\n", 
            SV_ARGV(text),
            SV_ARGV(comparator),
            sv_eq(text, comparator) ? "true" : "false"
          );

    comparator = sv_from_cstr("llo, Wor");
    printf("\""SV_FMT"\" contains \"" SV_FMT "\" => %s\n", 
            SV_ARGV(text),
            SV_ARGV(comparator),
            sv_contains(text, comparator) ? "true" : "false"
          );

    comparator = sv_from_cstr("llo, wor");
    printf("\""SV_FMT"\" contains \"" SV_FMT "\" => %s\n", 
            SV_ARGV(text),
            SV_ARGV(comparator),
            sv_contains(text, comparator) ? "true" : "false"
          );
}

void da_tests()
{
    da(Entity) entts = {0};
    Entity entt = {0};
    entt.id = 1;
    entt.name = "Foo";
    da_append(&entts, entt);
    entt.id = 2;
    entt.name = "Bar";
    da_append(&entts, entt);
    entt.id = 3;
    entt.name = "Buzz";
    da_append(&entts, entt);
    for(size_t i = 0; i < entts.count; ++i) {
        entt = entts.data[i];
        printf("ENTT[name: %s; id: %d]\n", entt.name, entt.id);
    }
}
