///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 F4HKW                                                      //
// for F4EXB / SDRAngel                                                          //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef DATVIDEORENDER_H
#define DATVIDEORENDER_H

#include <QWidget>
#include <QEvent>
#include <QIODevice>
#include <QThread>

#include "datvscreen.h"
#include "datvideostream.h"

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"

#include <libavutil/opt.h>
#include <libavutil/channel_layout.h>
#include <libavutil/common.h>
#include <libavutil/imgutils.h>
#include <libavutil/mathematics.h>
#include <libavutil/samplefmt.h>

#include "libswscale/swscale.h"

}

struct DataTSMetaData2
{
    int PID;
    int CodecID;
    QString Program;
    QString Stream;

    int Width;
    int Height;
    int BitRate;
    int Channels;
    QString CodecDescription;

    DataTSMetaData2()
    {
        PID=-1;
        CodecID=-1;
        Program="";
        Stream="";

        Width=-1;
        Height=-1;
        BitRate=-1;
        Channels=-1;
        CodecDescription="";
    }
};

class DATVideoRender : public DATVScreen
{
    Q_OBJECT
public:
    explicit DATVideoRender(QWidget * parent);
    void SetFullScreen(bool blnFullScreen);

    bool OpenStream(DATVideostream *objDevice);
    bool RenderStream();
    bool CloseStream(QIODevice *objDevice);

    struct DataTSMetaData2 MetaData;

private:
    bool m_blnRunning;
    bool m_blnIsFullScreen;

    bool m_blnIsFFMPEGInitialized;
    bool m_blnIsOpen;

    SwsContext *m_objSwsCtx;
    AVFormatContext *m_objFormatCtx;
    AVCodecContext *m_objDecoderCtx;
    AVFrame *m_objFrame;

    uint8_t *m_pbytDecodedData[4];
    int m_pintDecodedLineSize[4];

    int m_intFrameCount;
    int m_intVideoStreamIndex;

    int m_intCurrentRenderWidth;
    int m_intCurrentRenderHeight;

    bool InitializeFFMPEG();
    bool PreprocessStream();



protected:
    virtual bool eventFilter(QObject *obj, QEvent *event);

signals:

public slots:

};

class DATVideoRenderThread: public QThread
{

    public:
        DATVideoRenderThread()
        {
            m_objRenderer = NULL;
            m_objStream = NULL;
            m_blnRenderingVideo=false;
        }

        DATVideoRenderThread(DATVideoRender *objRenderer, DATVideostream *objStream)
        {
            m_objRenderer = objRenderer;
            m_objStream = objStream;
            m_blnRenderingVideo=false;
        }

        void setStreamAndRenderer(DATVideoRender *objRenderer, DATVideostream *objStream)
        {
            m_objRenderer = objRenderer;
            m_objStream = objStream;
            m_blnRenderingVideo=false;

        }

        void run()
        {
            if(m_blnRenderingVideo==true)
            {
                return;
            }

            if((m_objRenderer==NULL) || (m_objStream==NULL))
            {
                return ;
            }

            m_blnRenderingVideo=false;

            if(m_objRenderer->OpenStream(m_objStream))
            {
                printf("PID: %d W: %d H: %d Codec: %s Data: %s %s\r\n",m_objRenderer->MetaData.PID
                                                                      ,m_objRenderer->MetaData.Width
                                                                      ,m_objRenderer->MetaData.Height
                                                                      ,m_objRenderer->MetaData.CodecDescription.toStdString().c_str()
                                                                      ,m_objRenderer->MetaData.Program.toStdString().c_str()
                                                                      ,m_objRenderer->MetaData.Stream.toStdString().c_str());

                m_blnRenderingVideo=true;
            }

            while((m_objRenderer->RenderStream()) && (m_blnRenderingVideo==true))
            {
            }

            m_objRenderer->CloseStream(m_objStream);

        }

        void stopRendering()
        {
            m_blnRenderingVideo=false;
        }


    private:

        DATVideoRender *m_objRenderer;
        DATVideostream *m_objStream;
        bool m_blnRenderingVideo;
};

#endif // DATVIDEORENDER_H
