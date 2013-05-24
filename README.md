EXIF Thumbnail
==============

指定したEXIFファイルから、サムネイルを取得するライブラリ[libthumb](https://github.com/nkmrshn/libthumb)のRuby拡張ライブラリです。

実行例
------

これは、ruby 1.9.3で実行した例です。

    $ irb
    > require 'exif_thumbnail'
    => true 
    > foo = EXIFThumbnail.read("/Users/nkmrshn/Pictures/FOOD.JPG")
    => #<EXIFThumbnail:0x007fdd3a93cd20> 
    > foo.length
    => 12107 
    > foo.orientation
    => 6 
    > File.binwrite("/Users/nkmrshn/Desktop/Thumbnail.jpg", foo.data)
    => 12107 
    >

備考
----

ライセンスについては、LICENSE.mdをご覧下さい。
