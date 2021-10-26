{-# LANGUAGE CPP #-}
{-# LANGUAGE NoRebindableSyntax #-}
{-# OPTIONS_GHC -fno-warn-missing-import-lists #-}
module Paths_chap2 (
    version,
    getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

#if defined(VERSION_base)

#if MIN_VERSION_base(4,0,0)
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#else
catchIO :: IO a -> (Exception.Exception -> IO a) -> IO a
#endif

#else
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#endif
catchIO = Exception.catch

version :: Version
version = Version [0,1,0,0] []
bindir, libdir, dynlibdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/home/e-c/.cabal/bin"
libdir     = "/home/e-c/.cabal/lib/x86_64-linux-ghc-8.6.5/chap2-0.1.0.0-DDlFMmdIZmqEDe60M3Y4n5"
dynlibdir  = "/home/e-c/.cabal/lib/x86_64-linux-ghc-8.6.5"
datadir    = "/home/e-c/.cabal/share/x86_64-linux-ghc-8.6.5/chap2-0.1.0.0"
libexecdir = "/home/e-c/.cabal/libexec/x86_64-linux-ghc-8.6.5/chap2-0.1.0.0"
sysconfdir = "/home/e-c/.cabal/etc"

getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "chap2_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "chap2_libdir") (\_ -> return libdir)
getDynLibDir = catchIO (getEnv "chap2_dynlibdir") (\_ -> return dynlibdir)
getDataDir = catchIO (getEnv "chap2_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "chap2_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "chap2_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
