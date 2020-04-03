#region 程序集 Cognex.VisionPro.Core.dll, v53.2.0.0
// C:\Program Files (x86)\Cognex\VisionPro\ReferencedAssemblies\Cognex.VisionPro.Core.dll
#endregion

using Cognex.VisionPro.Implementation;
using Cognex.VisionPro.Implementation.Internal;
using System;
using System.ComponentModel;
using System.Drawing;
using System.Runtime.Serialization;

namespace Cognex.VisionPro
{
    // 摘要: 
    //     Object that describes a rectangular array of 8 bit grey scale pixels.
    //
    // 备注: 
    //     Interface that describes a rectangular array of 8 bit grey scale pixels.
    [Serializable]
    [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/CONTENT' />")]
    [CogDocSummary("Object that describes a rectangular array of 8 bit grey scale pixels.")]
    public class CogImage8Grey : CogObjectBase, ICogNetInternal, IDisposable, ICogImage, ICogImage8GreyData, ICloneable, ISerializable, ICogHasChanged, ICogChangedEvent
    {
        // 摘要: 
        //     This bit will be set in the EventArgs of a Changed event every time the value
        //     returned by CoordinateSpaceTree may have changed.
        [CogDocSummary("This bit will be set in the EventArgs of a Changed event every time the value returned by CoordinateSpaceTree may have changed.")]
        public const long SfCoordinateSpaceTree = 2;
        //
        // 摘要: 
        //     This bit will be set in the EventArgs of a Changed event every time the value
        //     returned by PixelFromRootTransform may have changed.
        [CogDocSummary("This bit will be set in the EventArgs of a Changed event every time the value returned by PixelFromRootTransform may have changed.")]
        public const long SfPixelFromRootTransform = 4;
        //
        // 摘要: 
        //     This bit will be set in the EventArgs of a Changed event every time the value
        //     returned by SelectedSpaceName may have changed.
        [CogDocSummary("This bit will be set in the EventArgs of a Changed event every time the value returned by SelectedSpaceName may have changed.")]
        public const long SfSelectedSpaceName = 1;

        // 摘要: 
        //     Constructs a new instance of this class.
        [CogDocSummary("Constructs a new instance of this class.")]
        public CogImage8Grey();
        //
        // 摘要: 
        //     Constructs a CogImage8Grey, copying or computing the pixels from the given
        //     bitmap.
        //
        // 参数: 
        //   bitmap:
        //     The Windows bitmap from which to copy or compute pixel values.
        [CogDocParam("bitmap", "The Windows bitmap from which to copy or compute pixel values.")]
        [CogDocSummary("Constructs a CogImage8Grey, copying or computing the pixels from the given bitmap.")]
        public CogImage8Grey(Bitmap bitmap);
        //
        // 摘要: 
        //     Constructs a new instance of this class as a deep copy of the given instance.
        //
        // 参数: 
        //   other:
        //     The instance to copy from.
        [CogDocParam("other", "The instance to copy from.")]
        [CogDocSummary("Constructs a new instance of this class as a deep copy of the given instance.")]
        public CogImage8Grey(CogImage8Grey other);
        //
        // 摘要: 
        //     Constructs a CogImage8Grey, allocating image memory with the given width
        //     and height.
        //
        // 参数: 
        //   width:
        //     The width of the new image.
        //
        //   height:
        //     The height of the new image.
        [CogDocParam("height", "The height of the new image.")]
        [CogDocParam("width", "The width of the new image.")]
        [CogDocSummary("Constructs a CogImage8Grey, allocating image memory with the given width and height.")]
        public CogImage8Grey(int width, int height);

        // 摘要: 
        //     Whether there is pixel data associated with this image.
        //
        // 备注: 
        //     Returns True if pixel data is associated with this image.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Allocated""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Allocated""]/ERROR_HRESULTS' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Allocated""]/CONTENT' />")]
        [CogDocSummary("Whether there is pixel data associated with this image.")]
        [CogDocValue(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Allocated""]/parameter[@retval=""1""]/CONTENT' />")]
        public override bool Allocated { get; }
        //
        // 摘要: 
        //     If nonzero, indicates that the raising of the Changed event has been suspended.
        //     This value is incremented when SuspendChangedEvent is called and decremented
        //     when ResumeAndRaiseChangedEvent is called.
        [Browsable(false)]
        [CogDocSummary("If nonzero, indicates that the raising of the Changed event has been suspended. This value is incremented when SuspendChangedEvent is called and decremented when ResumeAndRaiseChangedEvent is called.")]
        [Description("If nonzero, indicates that the raising of the Changed event has been suspended. This value is incremented when SuspendChangedEvent is called and decremented when ResumeAndRaiseChangedEvent is called.")]
        public override int ChangedEventSuspended { get; }
        //
        // 摘要: 
        //     Returns/sets the tree of all named coordinate spaces for this image. The
        //     tree provides advanced functions for managing coordinate spaces.
        //
        // 备注: 
        //     Returns or sets the Cognex.VisionPro.CogCoordinateSpaceTree for a particular
        //     image. You can use this tree to create a transform that maps points between
        //     coordinate spaces.To ensure that all acquired images have the same coordinate
        //     space tree, use Cognex.VisionPro.CogAcqFifo.Cognex.VisionPro.ICogAcqFifo.CoordinateSpaceTree
        //     instead.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""CoordinateSpaceTree""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""CoordinateSpaceTree""]/ERROR_HRESULTS' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""CoordinateSpaceTree""]/CONTENT' />")]
        [CogDocSummary("Returns/sets the tree of all named coordinate spaces for this image.  The tree provides advanced functions for managing coordinate spaces.")]
        [CogDocValue(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""CoordinateSpaceTree""]/parameter[@retval=""1""]/CONTENT' />")]
        public override CogCoordinateSpaceTree CoordinateSpaceTree { get; set; }
        //
        // 摘要: 
        //     If true, the serializable state of this object has changed since the last
        //     time it was serialized.
        [CogDocSummary("If true, the serializable state of this object has changed since the last time it was serialized.")]
        public override bool HasChanged { get; set; }
        //
        // 摘要: 
        //     Height of the image.
        //
        // 备注: 
        //     Returns the height of the image.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Height""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Height""]/ERROR_HRESULTS' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Height""]/CONTENT' />")]
        [CogDocSummary("Height of the image.")]
        [CogDocValue(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Height""]/parameter[@retval=""1""]/CONTENT' />")]
        [CogFilterThreshold(CogFilterThresholdConstants.Expanded)]
        public override int Height { get; }
        //
        // 摘要: 
        //     Transformation that maps points into pixel space ("#") from the root space
        //     ("@").
        //
        // 异常: 
        //   System.ArgumentException:
        //     The transform is NULL.
        //
        // 备注: 
        //     Returns the transformation that maps points into pixel space ("#") from the
        //     root space ("@").
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""PixelFromRootTransform""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""PixelFromRootTransform""]/ERROR_HRESULTS' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""PixelFromRootTransform""]/CONTENT' />")]
        [CogDocSummary(@"Transformation that maps points into pixel space (""#"") from the root space (""@"").")]
        [CogDocValue(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""PixelFromRootTransform""]/parameter[@retval=""1""]/CONTENT' />")]
        public override ICogTransform2D PixelFromRootTransform { get; set; }
        //
        // 摘要: 
        //     Returns/sets the name of the coordinate space to be used by tools which process
        //     this image.
        //
        // 异常: 
        //   Cognex.VisionPro.Exceptions.CogSpaceTreeInvalidNameSyntaxException:
        //     val is not a valid space name.
        //
        // 备注: 
        //     Returns or sets the name of the Cognex.VisionPro.CogCoordinateSpaceTree to
        //     be used by tools that process this image. VisionPro defines Framework.Coordinates.Theory.CoordSpaceNames
        //     for the root coordinate space, the pixel coordinate space, the screen coordinate
        //     space, as well as others.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""SelectedSpaceName""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""SelectedSpaceName""]/ERROR_HRESULTS' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""SelectedSpaceName""]/CONTENT' />")]
        [CogDocSummary("Returns/sets the name of the coordinate space to be used by tools which process this image.")]
        [CogDocValue(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""SelectedSpaceName""]/parameter[@retval=""1""]/CONTENT' />")]
        public override string SelectedSpaceName { get; set; }
        //
        // 摘要: 
        //     Width of the image.
        //
        // 备注: 
        //     Returns the width of the image.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Width""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Width""]/ERROR_HRESULTS' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Width""]/CONTENT' />")]
        [CogDocSummary("Width of the image.")]
        [CogDocValue(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Width""]/parameter[@retval=""1""]/CONTENT' />")]
        [CogFilterThreshold(CogFilterThresholdConstants.Expanded)]
        public override int Width { get; }

        // 摘要: 
        //     Occurs when one or more parts of the object's state may have changed.
        [CogDocSummary("Occurs when one or more parts of the object's state may have changed.")]
        public override event CogChangedEventHandler Changed;

        // 摘要: 
        //     Initialize the image with (undefined) pixel data of the given width and height.
        //     This method may not be called more than once.
        //
        // 参数: 
        //   width:
        //     The width of the image in pixels.
        //
        //   height:
        //     The height of the image in pixels.
        //
        // 异常: 
        //   Cognex.VisionPro.Exceptions.CogImageAllocateSizeException:
        //     The image is already allocated to a different size.
        //
        //   System.ArgumentException:
        //     width or height <= 0.
        //
        // 备注: 
        //     Initialize the image of the given height and width with undefined pixel data.
        //     You can call Cognex.VisionPro.ICogImage.Allocate(System.Int32,System.Int32)
        //     only once for an image. The allocated pixel space may not be resized.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Allocate""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Allocate""]/ERROR_HRESULTS' />")]
        [CogDocParam("height", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Allocate""]/parameter[@name=""Height""]/CONTENT' />")]
        [CogDocParam("width", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Allocate""]/parameter[@name=""Width""]/CONTENT' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Allocate""]/CONTENT' />")]
        [CogDocReturns(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""Allocate""]/parameter[@retval=""1""]/CONTENT' />")]
        [CogDocSummary("Initialize the image with (undefined) pixel data of the given width and height. This method may not be called more than once.")]
        public override void Allocate(int width, int height);
        //
        // 摘要: 
        //     Returns a deep copy of this class instance. Derived classes that implement
        //     Clone should override this method; other clients who wish to clone this instance
        //     should call ICloneable.Clone. See also CogSerializer.DeepCopyObject
        [CogDocSummary("Returns a deep copy of this class instance.  Derived classes that implement Clone should override this method; other clients who wish to clone this instance should call ICloneable.Clone. See also CogSerializer.DeepCopyObject")]
        protected virtual object Clone();
        //
        // 摘要: 
        //     Create a copy of this image in a new image. While the pixels will be copied,
        //     the CoordinateSpaceTree and PixelFromRootTransform will be shared.
        //
        // 返回结果: 
        //     The new image.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Copy""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Copy""]/ERROR_HRESULTS' />")]
        [CogDocReturns(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Copy""]/parameter[@retval=""1""]/CONTENT' />")]
        [CogDocSummary("Create a copy of this image in a new image. While the pixels will be copied, the CoordinateSpaceTree and PixelFromRootTransform will be shared.")]
        public CogImage8Grey Copy();
        //
        // 摘要: 
        //     Create a copy of this image in a new image. Pixels may be shared between
        //     images by specifying CopyMode=cogImageCopyModeSharePixels.
        //
        // 参数: 
        //   copyMode:
        //     The Cognex.VisionPro.CogImageCopyModeConstants.
        //
        // 返回结果: 
        //     The new image.
        //
        // 备注: 
        //     Creates a copy of this image in a new image. Pixels may be shared between
        //     images by specifying copyMode as Cognex.VisionPro.CogImageCopyModeConstants.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Copy""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Copy""]/ERROR_HRESULTS' />")]
        [CogDocParam("copyMode", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Copy""]/parameter[@name=""CopyMode""]/CONTENT' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Copy""]/CONTENT' />")]
        [CogDocReturns(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Copy""]/parameter[@retval=""1""]/CONTENT' />")]
        [CogDocSummary("Create a copy of this image in a new image. Pixels may be shared between images by specifying CopyMode=cogImageCopyModeSharePixels.")]
        public CogImage8Grey Copy(CogImageCopyModeConstants copyMode);
        //
        // 摘要: 
        //     Create a copy of this image in a new image. Pixels may be shared between
        //     images by specifying CopyMode=cogImageCopyModeSharePixels.
        //
        // 参数: 
        //   copyMode:
        //     The Cognex.VisionPro.CogImageCopyModeConstants.
        //
        // 返回结果: 
        //     The new image.
        //
        // 备注: 
        //     Creates a copy of this image in a new image. Pixels may be shared between
        //     images by specifying Cognex.VisionPro.CogImageCopyModeConstants as the copy
        //     mode.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""CopyBase""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""CopyBase""]/ERROR_HRESULTS' />")]
        [CogDocParam("copyMode", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""CopyBase""]/parameter[@name=""CopyMode""]/CONTENT' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""CopyBase""]/CONTENT' />")]
        [CogDocReturns(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""CopyBase""]/parameter[@retval=""1""]/CONTENT' />")]
        [CogDocSummary("Create a copy of this image in a new image. Pixels may be shared between images by specifying CopyMode=cogImageCopyModeSharePixels.")]
        public override ICogImage CopyBase(CogImageCopyModeConstants copyMode);
        //
        // 摘要: 
        //     Releases all resources used by this class instance. Only derived classes
        //     that implement Dispose should call this method; Other clients who wish to
        //     explicitly release resources should call IDisposable.Dispose. Do not attempt
        //     to access an object after it has been disposed.
        //
        // 参数: 
        //   disposing:
        //     Should be set to true when called from your public Dispose() method, thus
        //     disposing of all managed and unmanaged resources. It should be set to false
        //     when called from your Finalizer, thus disposing of only unmanaged resources.
        [CogDocParam("disposing", "Should be set to true when called from your public Dispose() method, thus disposing of all managed and unmanaged resources.  It should be set to false when called from your Finalizer, thus disposing of only unmanaged resources.")]
        [CogDocSummary("Releases all resources used by this class instance.  Only derived classes that implement Dispose should call this method; Other clients who wish to explicitly release resources should call IDisposable.Dispose.   Do not attempt to access an object after it has been disposed.")]
        protected virtual void Dispose(bool disposing);
        //
        // 摘要: 
        //     Gets an object that can be used to directly access pixel memory. The caller
        //     MUST call Dispose on this object when finished with it.
        //
        // 参数: 
        //   dataMode:
        //     Specifies whether the pixel data are read, write, or read/write.
        //
        //   x:
        //     The x-coordinate of the portion of the image to get.
        //
        //   y:
        //     The y-coordinate of the portion of the image to get.
        //
        //   width:
        //     The width of the image to get.
        //
        //   height:
        //     The height of the image to get.
        //
        // 返回结果: 
        //     An object that represents the pixel data.
        //
        // 异常: 
        //   Cognex.VisionPro.Exceptions.CogImageBadCoordException:
        //     x, y, height, and width describe a region that is not entirely within the
        //     image.
        //
        // 备注: 
        //     Gets an Cognex.VisionPro.CogImage8PixelMemory object that can be used to
        //     access pixel memory directly.  You must call this object's Cognex.VisionPro.ICogImage8PixelMemory.Dispose()
        //     method when you are finished with it.The x, y, height, and width parameters
        //     let you specify the portion of the image to get. To access the pixel memory
        //     for the entire image, specify zero for these parameters.  If you request
        //     Cognex.VisionPro.CogImageDataModeConstants or Cognex.VisionPro.CogImageDataModeConstants
        //     access to the pixel memory when you call Cognex.VisionPro.CogImage8Grey.Get8GreyPixelMemory(Cognex.VisionPro.CogImageDataModeConstants,System.Int32,System.Int32,System.Int32,System.Int32),
        //     the pixel memory may be copied internally.  Any changes that you make to
        //     the pixel may not be written back to the image until you call Cognex.VisionPro.ICogImage8PixelMemory.Dispose().
        //      Your application should assume that no changes to the image take place until
        //     then.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8GreyData""]/function[@vbname=""Get8GreyPixelMemory""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8GreyData""]/function[@vbname=""Get8GreyPixelMemory""]/ERROR_HRESULTS' />")]
        [CogDocParam("dataMode", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8GreyData""]/function[@vbname=""Get8GreyPixelMemory""]/parameter[@name=""DataMode""]/CONTENT' />")]
        [CogDocParam("height", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8GreyData""]/function[@vbname=""Get8GreyPixelMemory""]/parameter[@name=""Height""]/CONTENT' />")]
        [CogDocParam("width", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8GreyData""]/function[@vbname=""Get8GreyPixelMemory""]/parameter[@name=""Width""]/CONTENT' />")]
        [CogDocParam("x", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8GreyData""]/function[@vbname=""Get8GreyPixelMemory""]/parameter[@name=""X""]/CONTENT' />")]
        [CogDocParam("y", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8GreyData""]/function[@vbname=""Get8GreyPixelMemory""]/parameter[@name=""Y""]/CONTENT' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8GreyData""]/function[@vbname=""Get8GreyPixelMemory""]/CONTENT' />")]
        [CogDocReturns(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8GreyData""]/function[@vbname=""Get8GreyPixelMemory""]/parameter[@retval=""1""]/CONTENT' />")]
        [CogDocSummary("Gets an object that can be used to directly access pixel memory. The caller MUST call Dispose on this object when finished with it.")]
        public override ICogImage8PixelMemory Get8GreyPixelMemory(CogImageDataModeConstants dataMode, int x, int y, int width, int height);
        protected virtual void GetObjectData(SerializationInfo info, StreamingContext context);
        //
        // 摘要: 
        //     Pixel value at given location.
        //
        // 参数: 
        //   x:
        //     The pixel's x location.
        //
        //   y:
        //     The pixel's y location.
        //
        // 异常: 
        //   Cognex.VisionPro.Exceptions.CogImageNoPixelsException:
        //     Cognex.VisionPro.CogImage8Grey.Allocate(System.Int32,System.Int32) has not
        //     yet been called.
        //
        // 备注: 
        //     Returns the pixel value at given location.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/ERROR_HRESULTS' />")]
        [CogDocParam("x", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/parameter[@name=""X""]/CONTENT' />")]
        [CogDocParam("y", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/parameter[@name=""Y""]/CONTENT' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/CONTENT' />")]
        [CogDocReturns(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/parameter[@retval=""1""]/CONTENT' />")]
        [CogDocSummary("Pixel value at given location.")]
        public byte GetPixel(int x, int y);
        //
        // 摘要: 
        //     Returns the root image object that contains the raw pixel data.
        //
        // 参数: 
        //   root:
        //     The image data.
        //
        // 备注: 
        //     Returns the root image object that contains the raw pixel data.This function
        //     is not recommended to access raw pixel data.  Use Cognex.VisionPro.CogImage8Grey
        //     to directly access the image's pixel data.  This function is useful in cases
        //     where you want two images to share the same pixel data.  For example, you
        //     can pass the result of this function to Cognex.VisionPro.CogImage8Grey.SetRoot(Cognex.VisionPro.ICogImage8Root).
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""GetRoot""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""GetRoot""]/ERROR_HRESULTS' />")]
        [CogDocParam("root", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""GetRoot""]/parameter[@name=""Root""]/CONTENT' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""GetRoot""]/CONTENT' />")]
        [CogDocReturns(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""GetRoot""]/parameter[@retval=""1""]/CONTENT' />")]
        [CogDocSummary("Returns the root image object that contains the raw pixel data.")]
        public void GetRoot(out ICogImage8Root root);
        //
        // 摘要: 
        //     Returns a transform that maps points from the 'From' coordinate space to
        //     the 'To' space. The special string "." is accepted as an alias for the SelectedSpaceName
        //     of this image.
        //
        // 参数: 
        //   toSpaceName:
        //     The name of the coordinate space to transform the point to. The special string
        //     "." is accepted as an alias for the Cognex.VisionPro.ICogImage.SelectedSpaceName
        //     of this image.
        //
        //   fromSpaceName:
        //     The name of the coordinate space to transform the point from. The special
        //     string "." is accepted as an alias for the Cognex.VisionPro.ICogImage.SelectedSpaceName
        //     of this image.
        //
        // 返回结果: 
        //     The transform that maps a point from the fromSpaceName to the toSpaceName.
        //
        // 异常: 
        //   Cognex.VisionPro.Exceptions.CogImageNoTreeException:
        //     The coordinate space tree is missing.
        //
        // 备注: 
        //     Returns a transform that maps points from the 'From' coordinate space to
        //     the 'To' space. The special string "." is accepted as an alias for the Cognex.VisionPro.ICogImage.SelectedSpaceName
        //     of this image.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""GetTransform""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""GetTransform""]/ERROR_HRESULTS' />")]
        [CogDocParam("fromSpaceName", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""GetTransform""]/parameter[@name=""FromSpaceName""]/CONTENT' />")]
        [CogDocParam("toSpaceName", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""GetTransform""]/parameter[@name=""ToSpaceName""]/CONTENT' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""GetTransform""]/CONTENT' />")]
        [CogDocReturns(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage""]/function[@vbname=""GetTransform""]/parameter[@retval=""1""]/CONTENT' />")]
        [CogDocSummary(@"Returns a transform that maps points from the 'From' coordinate space to the 'To' space.  The special string ""."" is accepted as an alias for the SelectedSpaceName of this image.")]
        public override ICogTransform2D GetTransform(string toSpaceName, string fromSpaceName);
        protected void raise_Changed(object i1, CogChangedEventArgs i2);
        //
        // 摘要: 
        //     Re-enables raising of the Changed event after SuspendChangedEvent has been
        //     called. Also raises the Changed event if the ChangedEventSuspended count
        //     is reduced to zero and any changes were made while events were suspended.
        //     Must be called once for each call to SuspendChangedEvent.
        [CogDocSummary("Re-enables raising of the Changed event after SuspendChangedEvent has been called.  Also raises the Changed event if the ChangedEventSuspended count is reduced to zero and any changes were made while events were suspended. Must be called once for each call to SuspendChangedEvent.")]
        public override void ResumeAndRaiseChangedEvent();
        //
        // 摘要: 
        //     Creates a scaled version of this image. The dimensions of the returned image
        //     (in pixels) are specified by the width and height arguments. The scaling
        //     is performed using bilinear interpolation.
        //
        // 参数: 
        //   width:
        //     Width in pixels of the desired output image.
        //
        //   height:
        //     Height in pixels of the desired output image.
        //
        // 返回结果: 
        //     The scaled image.
        [CogDocParam("height", "Height in pixels of the desired output image.")]
        [CogDocParam("width", "Width in pixels of the desired output image.")]
        [CogDocReturns("The scaled image.")]
        [CogDocSummary("Creates a scaled version of this image. The dimensions of the returned image (in pixels) are specified by the width and height arguments. The scaling is performed using bilinear interpolation.")]
        public override ICogImage ScaleImage(int width, int height);
        //
        // 摘要: 
        //     Pixel value at given location.
        //
        // 参数: 
        //   x:
        //     The pixel's x location.
        //
        //   y:
        //     The pixel's y location.
        //
        //   value:
        //
        // 异常: 
        //   Cognex.VisionPro.Exceptions.CogImageNoPixelsException:
        //     Cognex.VisionPro.CogImage8Grey.Allocate(System.Int32,System.Int32) has not
        //     yet been called.
        //
        // 备注: 
        //     Returns the pixel value at given location.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/ERROR_HRESULTS' />")]
        [CogDocParam("value", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/parameter[@name=""value""]/CONTENT' />")]
        [CogDocParam("x", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/parameter[@name=""X""]/CONTENT' />")]
        [CogDocParam("y", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/parameter[@name=""Y""]/CONTENT' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/CONTENT' />")]
        [CogDocReturns(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""Pixel""]/parameter[@retval=""1""]/CONTENT' />")]
        [CogDocSummary("Pixel value at given location.")]
        public void SetPixel(int x, int y, byte value);
        //
        // 摘要: 
        //     Sets the root image object that contains the raw pixel data.
        //
        // 参数: 
        //   root:
        //     The image data.
        //
        // 备注: 
        //     Sets the root image object that contains the raw pixel data.It is legal to
        //     set root to NULL to disconnect the image from an existing root.
        [CogDocEvent("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""SetRoot""]/EVENTS' />")]
        [CogDocException("Txmog", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""SetRoot""]/ERROR_HRESULTS' />")]
        [CogDocParam("root", @"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""SetRoot""]/parameter[@name=""Root""]/CONTENT' />")]
        [CogDocRemarks(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""SetRoot""]/CONTENT' />")]
        [CogDocReturns(@"<include file='CognexCore.merged.xml' path='//interface[@name=""ICogImage8Grey""]/function[@vbname=""SetRoot""]/parameter[@retval=""1""]/CONTENT' />")]
        [CogDocSummary("Sets the root image object that contains the raw pixel data.")]
        public void SetRoot(ICogImage8Root root);
        //
        // 摘要: 
        //     Temporarily suspends the raising of the Changed event. May be called more
        //     than once, and a corresponding call to ResumeAndRaiseChangedEvent must be
        //     made for each call to SuspendChangedEvent.
        [CogDocSummary("Temporarily suspends the raising of the Changed event. May be called more than once, and a corresponding call to ResumeAndRaiseChangedEvent must be made for each call to SuspendChangedEvent.")]
        public override void SuspendChangedEvent();
        //
        // 摘要: 
        //     Creates a 24-bit RGB Windows bitmap from this image.
        //
        // 返回结果: 
        //     The 24-bit RGB Windows bitmap.
        [CogDocReturns("The 24-bit RGB Windows bitmap.")]
        [CogDocSummary("Creates a 24-bit RGB Windows bitmap from this image.")]
        public override Bitmap ToBitmap();
    }
}
