# geister-cpp-lib
ガイスターAI開発用の関連ファイル群です

## 使用方法

### ビルド
bin下で以下のコマンドを入力する。
```
make -j PLAYER_NAME=MyPlayer PLAYER_CLASS=MyPlayer
```
これにより、MyPlayer.soというファイルが生成される。

### 接続について
```
./client.out -H "接続先アドレス名" -p 10000 ./MyPlayer.so
```
これによりサーバーに接続することができる。
"-p 10000"は1万手を上限としていることを表している。

## 各ツールについて
- competition  
  自動対戦用ツールです．  
  ```
  competition {プレイヤ1パス} {プレイヤ2パス}
  ```
  と実行することで，プレイヤ1とプレイヤ2の対戦が実行されます．
  
- client    
  ```
  client -p {ポート番号} {プレイヤパス}
  ```
  のように使用します．