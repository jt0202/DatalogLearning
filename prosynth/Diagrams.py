#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

def Runtime():
    labels = ['Books', 'Countries', 'Family', 'Films','Locations']
    amie_times = [0.25 , 0.24, 0.12 , 0.11, 0.1]

    ps = [4281, 2687 , 395 , 1696 ,280]

    psn5 = [13880, 19616, 394, 15771, 276 ]

    x = np.arange(len(labels))
    width = 0.25

    fig, ax = plt.subplots()
    rects1 = ax.bar(x-width, amie_times, width, label='AMIE')
    rects2 = ax.bar(x, ps, width, label="OWA")
    rects3 = ax.bar(x+ width, psn5, width, label="PCA: 5%")

    ax.set_ylabel('Runtime in seconds')
    ax.set_yscale('log')
    ax.set_xticks(x, labels)
    ax.legend()
    ax.bar_label(rects1, padding=3)
    ax.bar_label(rects2, padding=3)
    ax.bar_label(rects3, padding=3)

    fig.tight_layout()
    plt.savefig("Runtimes.png")

def Correctness():
    labels = ['Books', 'Countries', 'Family', 'Films','Locations']
    amieT = [0.51 , 0.05, 0.4, 0.14, 0.04]
    amieF = [0.09, 0.03, 0.1, 0.14, 0.83]
    amieU = [0.4, 0.92, 0.5, 0.72, 0.13]


    ps = [4281, 2687 , 395 , 1696 ,280]

    psn5 = [13880, 19616, 394, 15771, 276 ]

    x = np.arange(len(labels))
    width = 0.2

    fig, ax = plt.subplots()
    ax.bar(x-width -0.05, amieT, width, label='AMIE', color="green")
    ax.bar(x-width -0.05, amieU, width, label='AMIE', bottom=amieT, color = "blue")
    ax.bar(x-width -0.05, amieF, width, label='AMIE', bottom=np.array(amieU)+np.array(amieT), color = "red")
    #rects2 = ax.bar(x, ps, width, label="OWA")
    #rects3 = ax.bar(x+ width, psn5, width, label="PCA: 5%")

    ax.set_xticks(x, labels)
    ax.legend()

    fig.tight_layout()
    plt.savefig("Correctness.png")

def Recall():
    labels = ['Books', 'Countries', 'Family', 'Films','Locations']
    amie = [0.09, 0.6, 0.12, 0.22, 0.04]

    ps = [0.73, 0.87 , 0.64 , 0.51 ,0.36]

    psn5 = [0, 0.87, 0.64, 0.51, 0.36 ]

    x = np.arange(len(labels))
    width = 0.25

    fig, ax = plt.subplots()
    rects1 = ax.bar(x-width, amie, width, label='AMIE')
    rects2 = ax.bar(x, ps, width, label="OWA")
    rects3 = ax.bar(x+ width, psn5, width, label="PCA: 5%")

    ax.set_ylabel('Recall in %')
    ax.set_xticks(x, labels)
    ax.legend()
    #ax.bar_label(rects1, padding=3)
    #ax.bar_label(rects2, padding=3)
    #ax.bar_label(rects3, padding=3)

    fig.tight_layout()
    plt.savefig("Recall.png")

if __name__ == "__main__":
    Correctness()
