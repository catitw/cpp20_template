project('function_template', 'cpp',
  default_options : ['cpp_std=c++20'])

sources = run_command('find', '.', '-name', '*.cpp').stdout().strip().split('\n')

foreach src : sources
  executable(
    src.split('/')[-1].split('.')[0],
    src
  )
endforeach