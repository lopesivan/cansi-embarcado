#!/usr/bin/env bash


echo INPUT: $*
[ "$3" ] || exit 1

LANGUAGE=${1^}
 PROJECT=$2
    FILE=$3

# if exist file `_f' then remove.
_f=model/$FILE
test -e $_f || { echo "file \`$_f' not found";exit 1; }

FILE_NAME_EXT=$(echo $FILE| sed 's/\./_/g')
FILE_NAME_EXT_TITLE=${FILE_NAME_EXT^}
    FILE_NAME=$(echo $FILE| sed 's/\..\+//g')
    FILE_NAME_LOWER=${FILE_NAME,,}
    FILE_NAME_TITLE=${FILE_NAME^}
          EXT=$(echo $FILE| sed 's/^.\+\.//g')

echo "LANGUAGE=$LANGUAGE"
echo " PROJECT=$PROJECT"
echo "FILE_NAME_EXT=$FILE_NAME_EXT"
echo "FILE_NAME_EXT_TITLE=$FILE_NAME_EXT_TITLE"
echo "    FILE_NAME=$FILE_NAME"
echo "    FILE_NAME=$FILE_NAME"
echo "    FILE_NAME_TITLE=$FILE_NAME_TITLE"
echo "          EXT=$EXT"

echo
echo  ===

echo create file: ConcreteFactoryCls${FILE_NAME_TITLE}.py
cat <<EOF >view/ConcreteFactoryCls${FILE_NAME_TITLE}.py
from Cls${FILE_NAME_TITLE} import Cls${FILE_NAME_TITLE}


class ConcreteFactoryCls${FILE_NAME_TITLE}:
    def get_ball(self, dataModel):
        return Cls${FILE_NAME_TITLE}(dataModel)
EOF


echo create file: Cls${FILE_NAME_TITLE}.py
cat <<EOF >view/Cls${FILE_NAME_TITLE}.py
# ${FILE_NAME_EXT_TITLE}
from ${LANGUAGE}.${PROJECT}.${FILE_NAME_EXT_TITLE} import ${FILE_NAME_EXT_TITLE}
from TemplateInterface import TemplateInterface


class Cls${FILE_NAME_TITLE}(TemplateInterface):
    def __init__(self, dataModel):
        self.__file = ${FILE_NAME_EXT_TITLE}()

        ${FILE_NAME_LOWER} = dataModel['${FILE_NAME_TITLE}']

        self.__file.${FILE_NAME_TITLE} = ${FILE_NAME_LOWER}[0]
        self.__file.${FILE_NAME_LOWER} = ${FILE_NAME_LOWER}[0].lower()

        ${FILE_NAME_TITLE}Types = ${FILE_NAME_LOWER}[1].keys()[0]
        self.__file.${FILE_NAME_TITLE}Types = ${FILE_NAME_LOWER}[1][${FILE_NAME_TITLE}Types]

    def put(self):
        fileName = "%s.${EXT}" % self.__file.${FILE_NAME_TITLE}
        print ("File: %s" % fileName)
        print (self.__file)

    def save(self):
        fileName = "%s.${EXT}" % self.__file.${FILE_NAME_TITLE}
        open(fileName, 'w').write(str(self.__file))
EOF

# ============================================================================
# AbstractFactory.py =========================================================
# ============================================================================
_o=view/AbstractFactory.py
echo "#Abstract Factory" > ${_o}
for f in view/ConcreteFactoryCls*.py; do
    a=$(echo $f| sed -e 's/.*view\///' -e 's/\.py$//')
    echo from $a import $a >> ${_o}
done

echo           >> ${_o}
echo "f = {"   >> ${_o}

for f in view/ConcreteFactoryCls*.py; do
    a=$(echo $f| sed -e 's/.*ConcreteFactoryCls//' -e 's/\.py$//')
    b=$(echo $f| sed -e 's/.*view\///' -e 's/\.py$//')
    echo "    '${a}': ${b}(),">> ${_o}
done

cat <<EOF>> ${_o}
}


class AbstractFactory:
    @staticmethod
    def get_factory(factory):
        return f[factory]
EOF

exit 0
