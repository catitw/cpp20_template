sources = run_command(
    'find', '.', '-maxdepth', '1', '-name', '*.cpp', 
    check: true
  ).stdout().strip().split('\n')

foreach src : sources
  executable(
    src.split('/')[-1].split('.')[0],
    sources: src,
    dependencies: [utils_dep]
  )
endforeach
