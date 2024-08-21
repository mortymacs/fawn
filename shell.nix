{ pkgs ? import <nixpkgs> {} }:
with pkgs;

mkShell {
    nativeBuildInputs = [
        gcc
        pkg-config
    ];
    buildInputs = [
        glib
        gobject-introspection
        gtk3
        gtk4
    ];
}
