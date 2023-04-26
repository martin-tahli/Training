from simulator.simulation import simulation
from simulator.actions import actions
from vehicle.saloon import saloon
from vehicle.engine import engine
from vehicle.braking_system import braking_system

if __name__ == "__main__":
    simulation.simulation()
    actions.actions()
    saloon.saloon()
    engine.engine()
    braking_system.brakes()
