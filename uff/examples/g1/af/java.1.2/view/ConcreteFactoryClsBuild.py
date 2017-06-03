from ClsBuild import ClsBuild


class ConcreteFactoryClsBuild:
    def get_ball(self, build):
        return ClsBuild(build)
