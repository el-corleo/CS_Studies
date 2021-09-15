import os
working_dir = os.path.dirname(os.path.realpath(__file__))
for fn in os.listdir(working_dir):
  if not os.path.isdir(os.path.join(working_dir, fn)):
    continue # Not a directory
  tokens = fn.rpartition(' ')
  new_name = '第' + tokens[0][-2:] + '巻'
  print(new_name)
  os.rename(os.path.join(working_dir, fn), os.path.join(working_dir, new_name))