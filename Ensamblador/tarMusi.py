from pprint import pprint

import numpy as np

from scipy.io.wavfile import write

import sounddevice as sd 

import soundfile as sf

samplerate = 44100 #Frequecy in Hz

def main(data):
    data = data * (16300/np.max(data)) # Adjusting the Amplitude (Optional)

    write('cancion.wav', samplerate, data.astype(np.int16))

    filename = 'cancion.wav'

    data, fs = sf.read(filename, dtype='float32')

    sd.play(data,fs)

    status = sd.wait()

