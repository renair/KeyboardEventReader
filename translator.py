import pickle
import os.path as path

vocabular_file = 'vocabular.v'
file_to_read = 'log.txt'

if path.isfile(vocabular_file):
    vocabular = pickle.load(open(vocabular_file,'rb'))
output = ''
for sym in open(file_to_read).read().split(' '):
        if not vocabular.get(sym) and sym != '\n':
            vocabular[sym] = input('Char for '+sym+':')
            print(vocabular)
        output += vocabular[sym]
print(output)
pickle.dump(vocabular,open(vocabular_file,'wb'))
