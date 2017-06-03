from ClsMakefile import ClsMakefile


class ConcreteFactoryClsMakefile:
    def get_ball(self, dataModel):
        return ClsMakefile(dataModel)