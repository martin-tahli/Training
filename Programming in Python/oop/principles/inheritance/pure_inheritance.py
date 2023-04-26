class CouldNotConnectToExternalTempDevice(Exception):
    pass


connected = False
if not connected:
    raise CouldNotConnectToExternalTempDevice("I failed to establish connection")
