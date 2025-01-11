project('cpp20_template', 'cpp',
  version : '0.1',
  default_options : ['cpp_std=c++20'])

chapters = [
  'function_template',
  'class_template'
]

subdir('utils')

foreach chapter : chapters
  subdir('chapters' / chapter)
endforeach
