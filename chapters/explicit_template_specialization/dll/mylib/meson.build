mylib = library('mylib', 
    sources: ['impl.cpp'],
)

mylib_dep = declare_dependency(
    dependencies: [], 
    include_directories : include_directories('.'), 
    link_with : mylib
)