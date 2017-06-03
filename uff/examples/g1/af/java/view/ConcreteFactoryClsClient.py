from ClsClient import ClsClient


class ConcreteFactoryClsClient:
    def get_ball(self, dataModel):
        return ClsClient(dataModel)
