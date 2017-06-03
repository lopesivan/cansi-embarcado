from JavaClassFamily import JavaClassFamily


class ConcreteFactoryFamily:
    def get_ball(self, dataModel):
        return JavaClassFamily(dataModel)
