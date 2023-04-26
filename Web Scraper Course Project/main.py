from module.modules.input_check import input_check
from module.modules.Flow_control import Flow_control

if __name__ == "__main__":
    args = input_check()
    flow = Flow_control(args)
    flow.hud()
