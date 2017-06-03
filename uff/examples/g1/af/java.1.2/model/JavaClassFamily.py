# ${Family_java}
from Python.af.${Family_java} import ${Family_java}
from ${TemplateInterface} import ${TemplateInterface}


class ${JavaClassFamily}(${TemplateInterface}):
    def __init__(self, dataModel):
        self.__file = ${Family_java}()

        family = dataModel['Family']

        self.__file.Family = family[0]
        self.__file.family = family[0].lower()

        FamilyTypes = family[1].keys()[0]
         self.__file.FamilyTypes = family[1][FamilyTypes]

     def put(self):
        fileName = "%s.java" % self.__file.Family
        print ("File: %s" % fileName)
        print (self.__file)

     def save(self):
        fileName = "%s.java" % self.__file.Family
        open(fileName, 'w').write(str(self.__file))
