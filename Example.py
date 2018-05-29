import time
from homegear import Homegear

# This callback method is called on Homegear variable changes
def eventHandler(peerId, channel, variableName, value):
	# Note that the event handler is called by a different thread than the main thread. I. e. thread synchronization is
	# needed when you access non local variables.
	print(peerId, channel, variableName, value);

hg = Homegear("/var/run/homegear/homegearIPC.sock", eventHandler);

# hg waits until the connection is established (but for a maximum of 2 seonds).

print(hg.logLevel());
print(hg.listDevices());

while(hg.connected()):
	time.sleep(1);
