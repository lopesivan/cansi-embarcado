from ClsFamily import ClsFamily


class ConcreteFactoryClsFamily:
    def get_ball(self, dataModel):
        return ClsFamily(dataModel)
