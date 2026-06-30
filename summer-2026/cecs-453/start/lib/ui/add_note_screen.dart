import 'package:firebase_auth_flutterfire_ui/data/note_model.dart';
import 'package:firebase_auth_flutterfire_ui/providers/note_provider.dart';
import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

class AddNoteScreen extends StatefulWidget {
  final Note? note;
  const AddNoteScreen({super.key, this.note});
  @override
  State<AddNoteScreen> createState() => _AddNoteScreenState();
}

class _AddNoteScreenState extends State<AddNoteScreen> {
  final _formKey = GlobalKey<FormState>();
  late final _titleController = TextEditingController(text: widget.note?.title);
  late final _descriptionController = TextEditingController(
    text: widget.note?.description,
  );

  void _saveNote() {
    if (_formKey.currentState!.validate()) {
      final newNote = Note(
        id: widget.note?.id,
        title: _titleController.text,
        description: _descriptionController.text,
        createdAt: DateTime.now(),
      );
      // Use the provider to save the note
      final provider = Provider.of<NoteProvider>(context, listen: false);
      if (widget.note == null) {
        provider.addNote(newNote);
      } else {
        provider.updateNote(newNote);
      }
      Navigator.pop(context);
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.note == null ? 'Add Note' : 'Update Note'),
      ),
      body: Form(
        key: _formKey,
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Column(
            children: [
              TextFormField(
                controller: _titleController,
                decoration: const InputDecoration(labelText: 'Title'),
                validator: (value) {
                  if (value == null || value.isEmpty) {
                    return 'Title is required';
                  }
                  return null;
                },
              ),
              TextFormField(
                controller: _descriptionController,
                decoration: const InputDecoration(labelText: 'Description'),
                validator: (value) {
                  if (value == null || value.isEmpty) {
                    return 'Description is required';
                  }
                  return null;
                },
              ),
              if (widget.note != null)
                Column(
                  children: [
                    SizedBox(height: 10),
                    Text(
                      'Created at: ${widget.note!.createdAt.toLocal().toIso8601String()}',
                      style: const TextStyle(fontSize: 12),
                    ),
                  ],
                ),
              const SizedBox(height: 20),
              ElevatedButton(
                onPressed: _saveNote,
                child: Text(widget.note == null ? 'Add Note' : 'Update Note'),
              ),
              const SizedBox(height: 20),
              ElevatedButton(
                onPressed: () {
                  Navigator.pop(context);
                },
                child: const Text('Cancel'),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
