project('cpp20_template', 'cpp',
  version : '0.1',
  default_options : ['cpp_std=c++20'])

chapters = [
  'function_template',
  'class_template',
  'variable_template',
  'full_template_specialization',
  'partial_specialization',
  'explicit_template_specialization',
  'fold_expression',
  'dependent_name',
  'SFINAE',
  'concept_and_requires'
]

subdir('utils')

foreach chapter : chapters
  subdir('chapters' / chapter)
endforeach
