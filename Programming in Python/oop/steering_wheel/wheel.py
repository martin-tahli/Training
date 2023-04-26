class SteeringWheel:
    def __init__(
            self,
            color,
            diameter,
            material="cheap",
            form="circle",
            airbag=None,
            volume_control=False,
            radio_connector=None,
    ):
        self.position = 0
        self.color = color
        self.diameter = diameter
        self.material = material
        self.form = form
        self.airbag = airbag

        # Add logic to ensure that you have radio_connector if volume_control is True.
        self.radio_connector = self.__ensure_radio_connecter_if_needed(
            volume_control, radio_connector,
        )

    def __ensure_radio_connecter_if_needed(self, volume_control, radio_connector):
        if not volume_control:
            return
        if radio_connector is None:
            raise Exception("Missing radio connector")
        return radio_connector

    def steer_left(self):
        self.position -= 10
        self.__get_position()
        self.auto_steer_to_initial()

    def steer_right(self):
        self.position += 10
        self.__get_position()
        self.auto_steer_to_initial()

    def auto_steer_to_initial(self):
        self.position = 0
        self.__get_position()

    def __get_position(self):
        print(f"Wheel steered to {self.position}")

    def increase_volume(self):
        if self.radio_connector:
            self.radio_connector.volume_up()

    def decrease_volume(self):
        if self.radio_connector:
            self.radio_connector.volume_down()


normal_wheel = SteeringWheel("black", "40sm", "leather", airbag="Special")
# Make another wheel which has custom Airbag as Airbag instance.
print(type(normal_wheel), isinstance(normal_wheel, SteeringWheel))
print(normal_wheel.airbag)
print(normal_wheel.color)
print(normal_wheel.diameter)
print(normal_wheel.material)
print(f"Wheel initial position: {normal_wheel.position}")
normal_wheel.steer_right()
