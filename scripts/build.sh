#!/usr/bin/env bash

pushd popl2020-artifact
    pushd prosynth/souffle
        ./bootstrap
        ./configure
        make -j 8
    popd
popd

