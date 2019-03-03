/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.nio.CharBuffer;

/**
 *
 * @author vench
 */
public class HtmlReader {
    
    private static final int STATE_OPEN_TAG = 1;
    private static final int STATE_OPEN_TAG_SPACE = 2;
    private static final int STATE_CLOSE_TAG = 4;
    private static final int STATE_CLOSE_TAG_OPEN = 8; 
    
    private final Reader reader;
    private boolean openHead;
    private boolean openScript;
    private int state;
    private int spaceCount;
    
    private StringBuilder lastTag;
    
    
    HtmlReader(Reader in) {
        reader = in;
    }
    
    public String getText() throws IOException {
        StringBuilder sb = new StringBuilder(); 
        int c; 
        while((c = reader.read()) != -1) {
            char ch = (char)c;
            if(addToText(ch)) { 
                sb.append(ch); 
            } 
        } 
        
        return sb.toString();
    }
    
    
    
    private boolean addToText(char c) {
        if(isOpenTag(c)) {
            state = STATE_OPEN_TAG;
            lastTag = new StringBuilder(); 
            return false;
        } else if(isCloseTag(c)) {
            state = STATE_CLOSE_TAG;
             
            if(!openHead && "head".equals(lastTag.toString())) {
                openHead = true;
            }
            if(openHead && "/head".equals(lastTag.toString())) {
                openHead = false;
            }
            if(!openScript && "script".equals(lastTag.toString())) {
                openScript = true;
            }
            if(openScript && "/script".equals(lastTag.toString())) {
                openScript = false;
            }
            
            return false;
        } else if(state == STATE_OPEN_TAG && isSpace(c)) { 
            state = STATE_OPEN_TAG_SPACE; 
            return false;
        } 
        if(state == STATE_OPEN_TAG) {
            lastTag.append(c);
            return false;
        } 
        if(state == STATE_OPEN_TAG_SPACE) {
            return false;
        } 
        
        if(isSpace(c)) {
            spaceCount ++;
        } else {
            spaceCount = 0;
        }
        
        return !openHead && !openScript && spaceCount < 2;
    }
    
    private boolean isSpace(char c) {
        return Character.isWhitespace(c);
    }
    
    private boolean isOpenTag(char c) {
        return c == '<';
    }
    
    private boolean isCloseTag(char c) {
        return c == '>';
    } 
    
}
