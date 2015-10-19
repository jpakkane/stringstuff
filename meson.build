project('stringstuff', 'cpp', version : '0.1.0')

gtest_dep = dependency('gtest', required : false, main : true)
gtest_src = []
gtest_inc = []
if not gtest_dep.found()
  gtest_proj = subproject('gtest')
  gtest_dep = []
  gtest_src = [gtest_proj.get_variable('mainsources'), gtest_proj.get_variable('libsources')]
  gtest_inc = gtest_proj.get_variable('incdir')
endif

inc = include_directories('include')
subdir('test')
