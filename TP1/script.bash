sed 's/\./.\n/g' breve_historia.txt | sed '/^\s*$/d' > breve_historia_2.txt

egrep -i -o "[A-Z][^.]*\<GUERRA\>[^.]*\.  |[A-Z][^.]*\<GUERRA\>[^.]*\.\n*" breve_historia.txt

egrep "A.*s\.\n*" breve_historia.txt

egrep -i -c "[A-Z][^.]*PERONISMO[^.]*\. " breve_historia.txt

egrep -o "[A-Z][^.]*\<Sarmiento\>*[^.]*\. |[A-Z][^.]*\<Sarmiento\>*[^.]*\.\n*" breve_historia.txt | egrep -c  "[A-Z][^.]*\<Rosas\>*[^.]*\. |[A-Z][^.]*\<Rosas\>*[^.]*\.\n*" 

egrep -o "[A-Z][^.]*18..[^.]*\. |[A-Z][^.]*18..[^.]*\.\n*" breve_historia.txt

sed "s/^[A-Z][^ ]* //g" breve_historia.txt

ls | egrep -o "[^.]*\.txt"