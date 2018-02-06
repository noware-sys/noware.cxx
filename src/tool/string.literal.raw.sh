#! /bin/bash

# usage: $0 input.file output.file [delimiter]

delimiter_default='';

#echo "${#}";
if test "${#}" -lt 2
then
	if test "${1}" == '--help'
	then
		filename=$(basename ${0});
		
		echo "${filename}"': usage: '"'./${filename}'"' input.file output.file [delimiter]';
		exit 0;
	fi
	
	exit 1;
fi

if test -z "${3}"
then
	delimiter="${delimiter_default}";
else
	delimiter="${3}";
fi


> "${2}";

echo -e -n "u8R\"""${delimiter}""(" >> "${2}";

cat "${1}" >> "${2}";

#echo -e -n ")""${delimiter}""\"\n" >> "${2}";
echo -e -n ")""${delimiter}""\"" >> "${2}";
