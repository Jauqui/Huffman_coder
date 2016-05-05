#-------------------------------------------------
#
# Project created by QtCreator 2014-11-17T13:14:49
#
#-------------------------------------------------

#QT       += core

#QT       -= gui

TARGET = Huffman_coding
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += HuffmanCoder.h HuffmanTree.h
SOURCES += HuffmanCoder.cpp  HuffmanTree.cpp main.cpp

OTHER_FILES += \
    data/Huffman_text.txt
