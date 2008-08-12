# test of iovInpector

import os,os.path,string,commands
import pluginCondDBPyInterface as CondDB
from CondCore.Utilities import iovInspector as inspect


class How(int) :
    __init__(self):
        self.a=0
        self.b=1
        self.c=2


class TestWhat :
    """
    a fake What class
    """
    def __init__(self) :
        self.__how = How()
        self.__which = CondDB.VInt()
    def how(self) :
        return self.__how
    def which(self):
        return self.__which
    def set_how(self,h):
        self.__how=h
    def set_which(self,vi) :
        self.__which = vi
    def descr_which(self):
        d = CondDB.VString()
        d.append('me')
        d.append('you')
        d.append('her')
        return d;
